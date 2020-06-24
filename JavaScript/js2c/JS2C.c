

/******************************** -- Libraries -- *****************************/
#include <stdio.h> /* puts, printf */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strlen */
#include <assert.h> /* assert */
#include <map> /* map */

using namespace std;

#define UNUSED(x) ((void)x)

enum {FALSE, TRUE};

typedef struct property property_t;
typedef struct object object_t;
typedef struct prototype prototype_t;
typedef struct contructor constructor_t;
typedef object_t *(*ctor_func_t)(object_t *_this, void *args);
typedef void (*define_property_t)(object_t *_this, char *property_name,
								  property_t property);
typedef int (*property_is_enumerable_t)(object_t *_this, char *property_name);								  
typedef char *(*to_string_func_t)(object_t *_this);
typedef void *(*value_of_func_t)(object_t *_this);
typedef int (*is_prototype_of_func_t)(object_t *_this, object_t *obj);
typedef int (*has_own_property_func_t)(object_t *_this, char *prop_name);
typedef void (*shape_say_hi_func_t)(object_t *_this);
typedef void (*shape_print_color_t)(object_t *_this);
typedef size_t (*rectangle_get_area_t)(object_t *_this);


/******************************* -- Structs -- ********************************/
struct property
{
	void *value;
	int enumerable;
	int configurable;
	int writable;
};

struct object
{
	prototype_t *proto; /*TODO isn't proto a property of object?*/
	map<const char *, property_t> properties;
};

struct prototype 
{
	object_t object;
	char *type_name;
	constructor_t *constructor;  /*TODO isn't constructor a property of prototype?*/
	/*TODO aren't properties supposed to be as the property struct?*/
};

struct contructor
{
/*TODO isn't prototype a property of constructor/function?*/
	prototype_t prototype; /*TODO by value or by reference*/
	ctor_func_t ctor_func;
};


/************************ -- Forward Declarations -- **************************/

/* FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME */
object_t *ObjectCtor(object_t *_this, void *args);
object_t *ShapeCtor(object_t *_this, void *args);
object_t *RectangleCtor(object_t *_this, void *args);
object_t *SquareCtor(object_t *_this, void *args);



/******************************** -- General -- *******************************/
object_t *New()
{
	object_t *_this = (object_t *)malloc(sizeof(object_t));
	
	return _this;
}

int InstanceOf(object_t *obj, constructor_t *ctor)
{
	prototype_t *curr_proto;
	
	for ( curr_proto = obj->proto
	 	 ; NULL != curr_proto
	 	 ; curr_proto = curr_proto->object.proto )
	{
		if (curr_proto->constructor == ctor)
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

/******************************* -- Globals -- ********************************/
char to_string_buffer[100000000];

const char *G_PRIMITIVES[] = {"String", "Number", "Boolean", "Symbol", "BigInt"};


map<const char *, property_t> OBJ_PROTOTYPE_MAP;
prototype_t OBJECT_PROTOTYPE = {{NULL, OBJ_PROTOTYPE_MAP},
								(char *)"Object", NULL};
constructor_t OBJECT_CTOR = {OBJECT_PROTOTYPE, ObjectCtor};


map<const char *, property_t> SHAPE_PROTOTYPE_MAP;
prototype_t SHAPE_PROTOTYPE = {{&(OBJECT_CTOR.prototype), SHAPE_PROTOTYPE_MAP},
							   (char *)"Shape", NULL};
constructor_t SHAPE_CTOR = {SHAPE_PROTOTYPE, ShapeCtor};


map<const char *, property_t> RECTANGLE_PROTOTYPE_MAP;
prototype_t RECTANGLE_PROTOTYPE = {{&(SHAPE_CTOR.prototype),
									RECTANGLE_PROTOTYPE_MAP},
								    (char *)"Rectangle", NULL};
constructor_t RECTANGLE_CTOR = {RECTANGLE_PROTOTYPE, RectangleCtor};

map<const char *, property_t> SQUARE_PROTOTYPE_MAP;
prototype_t SQUARE_PROTOTYPE = {{&(RECTANGLE_CTOR.prototype),
								 SQUARE_PROTOTYPE_MAP},
								 (char *)"Square", NULL};
constructor_t SQUARE_CTOR = {SQUARE_PROTOTYPE, SquareCtor};




/******************************* -- Constructors -- ***************************/
object_t *ObjectCtor(object_t *_this, void *args)
{
	map<const char *, property_t> OBJ_MAP;

	UNUSED(args);
	
	_this->proto = &(OBJECT_CTOR.prototype);
	_this->properties = OBJ_MAP;
	
	return _this;
}

object_t *ShapeCtor(object_t *_this, void *args)
{
	ObjectCtor(_this, NULL);

	_this->proto = &(SHAPE_CTOR.prototype);
	_this->properties.insert({"color", {args,TRUE, TRUE, TRUE}});
}

object_t *RectangleCtor(object_t *_this, void *args)
{
	ShapeCtor(_this, (void *)"black");

	size_t *width = ((size_t *)args);
	size_t *length = ((size_t *)args + 1);

	_this->proto = &(RECTANGLE_CTOR.prototype);
	_this->properties.insert({"width", {width, TRUE, TRUE, TRUE}});
	_this->properties.insert({"length", {length, TRUE, TRUE, TRUE}});
	
	void *func = 
	(_this->proto->object.proto->object.properties.find("printColor")->second).value;
	
	((shape_print_color_t)func)(_this);
}

object_t *SquareCtor(object_t *_this, void *args)
{
	ObjectCtor(_this, args); //XXX in JS file, Square do not inherit Rectangle's Ctor
	
	size_t *width = ((size_t *)args);
	size_t *length = ((size_t *)args);
	
	_this->proto = &(SQUARE_CTOR.prototype);
	_this->properties.insert({"width", {width, TRUE, TRUE, TRUE}});
	_this->properties.insert({"length", {length, TRUE, TRUE, TRUE}});
}

/******************************* -- Object Methods -- **************************/
int ObjectHasOwnProperty(object_t *_this, char *prop_name)
{
	return _this->properties.find(prop_name) != _this->properties.end();
}

int ObjectIsPrototypeOf(object_t *_this, object_t *obj)
{
	return (prototype_t *)_this == obj->proto;
}

int IsPrimitive(object_t *obj)
{
	char *target_type = obj->proto->type_name;
	size_t i = 0;
	size_t primitive_arr_len = sizeof(G_PRIMITIVES) / sizeof(*G_PRIMITIVES);
	
	for (i = 0; i < primitive_arr_len; ++i)
	{
		if (0 == strcmp(target_type, G_PRIMITIVES[i]))
		{
			return TRUE;
		}
	}
	
	return FALSE;
} 

void *ObjectValueOf(object_t *_this)
{
	if (IsPrimitive(_this))
	{
		return (_this->properties.find("primitiveValue")->second).value;
	}
	
	return _this;
}

char *ObjectToString(object_t *_this)
{
	char *name = _this->proto->type_name;
	
	/*sprintf(to_string_buffer, "[object %s]", name);*/
	sprintf(to_string_buffer, "[object Object]");
	
	return to_string_buffer;
}

void ObjectDefineProperty(object_t *_this, char *property_name, property_t property)
{
	_this->properties.insert({property_name, property});
}

int ObjectPropertyIsEnumerable(object_t *_this, char *property_name)
{	
	if (_this->properties.end() == _this->properties.find(property_name))
	{
		return FALSE;
	}
	
	return ((_this->properties.find(property_name)->second).enumerable);
}

/******************************* -- Shape Methods -- **************************/
void ShapePrintColor(object_t *_this)
{
	char *color = (char *)((_this->properties.find("color")->second).value);
	puts(color);
}

void ShapeSayHi(object_t *_this) 
{
	puts("Hi");
}

char *ShapeToString(object_t *_this)
{
	sprintf(to_string_buffer,"[Shape %s]",
					(char *)(_this->properties.find("color")->second).value);
	
	return to_string_buffer;						 
}

/**************************** -- Rectangle Methods -- *************************/
size_t RectangleGetArea(object_t *_this)
{
	size_t width = *(size_t *)((_this->properties.find("width")->second).value);
	size_t length = *(size_t *)((_this->properties.find("length")->second).value);
	
	return (width * length);
}

char *RectangleToString(object_t *_this)
{
	size_t width = *(size_t *)((_this->properties.find("width")->second).value);
	size_t length = *(size_t *)((_this->properties.find("length")->second).value);
	
	sprintf(to_string_buffer, "[Rectangle %lu X %lu]", length, width);
					
	return to_string_buffer;
}


/***************************** -- Inits Prototypes -- *************************/
void InitObjectPrototype()
{
	// adding the constructor to the Object Prototype
	OBJECT_CTOR.prototype.constructor = &OBJECT_CTOR;
	
	// init prototype methods
	OBJECT_CTOR.prototype.object.properties.insert(
					{"toString", {(void *)ObjectToString, TRUE, TRUE, TRUE}}
	);
	OBJECT_CTOR.prototype.object.properties.insert(
					{"valueOf", {(void *)ObjectValueOf, TRUE, TRUE, TRUE}}
	);
	OBJECT_CTOR.prototype.object.properties.insert(
					{"isPrototypeOf", {(void *)ObjectIsPrototypeOf, TRUE, TRUE, TRUE}}
	);
	OBJECT_CTOR.prototype.object.properties.insert(
					{"hasOwnProperty", {(void *)ObjectHasOwnProperty, TRUE, TRUE, TRUE}}
	);
	OBJECT_CTOR.prototype.object.properties.insert(
					{"defineProperty", {(void *)ObjectDefineProperty, TRUE, TRUE, TRUE}}
	);
	OBJECT_CTOR.prototype.object.properties.insert(
					{"propertyIsEnumerable", {(void *)ObjectPropertyIsEnumerable, TRUE, TRUE, TRUE}}
	);
}

void InitShapePrototype()
{
	// adding the constructor to the Shape Prototype
	SHAPE_CTOR.prototype.constructor = &SHAPE_CTOR;
	
	// init prototype methods
	SHAPE_CTOR.prototype.object.properties.insert(
					{"printColor", {(void *)ShapePrintColor, TRUE, TRUE, TRUE}}
	);
	
	SHAPE_CTOR.prototype.object.properties.insert(
					{"toString", {(void *)ShapeToString, TRUE, TRUE, TRUE}}
	);
}

void InitRectanglePrototype()
{
	// adding the constructor to the Rectangle Prototype
	RECTANGLE_CTOR.prototype.constructor = &RECTANGLE_CTOR;
	
	// init prototype methods
	RECTANGLE_CTOR.prototype.object.properties.insert(
					{"getArea", {(void *)RectangleGetArea, TRUE, TRUE, TRUE}}
	);
	
	RECTANGLE_CTOR.prototype.object.properties.insert(
					{"toString", {(void *)RectangleToString, TRUE, TRUE, TRUE}}
	);
}

void InitSquarePrototype()
{
	// adding the constructor to the Square Prototype
	SQUARE_CTOR.prototype.constructor = &SQUARE_CTOR;
}


/********************************* -- MAIN --**********************************/
int main()
{
	InitObjectPrototype();
	InitShapePrototype();
	InitRectanglePrototype();
	InitSquarePrototype();
	
	{
		object_t *ret_val = NULL;
		
	//line 1
		object_t *obj = New();
		OBJECT_CTOR.ctor_func(obj, NULL);
	
	//line 2
		object_t *obj2 = New();
		OBJECT_CTOR.ctor_func(obj, NULL);

	//line 3
		void *func = (obj->proto->object.properties.find("toString")->second).value;
		printf("%s\n", ((to_string_func_t)func)(obj));
	//line 4

		func = ((obj->proto->object.properties.find("valueOf"))->second).value;
		ret_val = (object_t *)(((value_of_func_t)func)(obj));
		func = (ret_val->proto->object.properties.find("toString")->second).value;
		puts(((to_string_func_t)func)(obj));


	//line 5
		func = (obj->proto->object.properties.find("isPrototypeOf")->second).value;
		printf("%d\n", ((is_prototype_of_func_t)func)(obj, obj2));

	//line 6
		func = (OBJECT_CTOR.prototype.object.properties.find("isPrototypeOf")->second).value;
		printf("%d\n", ((is_prototype_of_func_t)func)((object_t *)(&OBJECT_CTOR.prototype), obj));
		
	//line 7
		func = (OBJECT_CTOR.prototype.object.properties.find("hasOwnProperty")->second).value;
		printf("%d\n", ((has_own_property_func_t)func)(obj, (char *)"toString"));

	//line 8
		func = (OBJECT_CTOR.prototype.object.properties.find("hasOwnProperty")->second).value;
		printf("%d\n", ((has_own_property_func_t)func)(obj, (char *)"name"));	
		
	//line 9
		obj->properties.insert({"name", {(void *)"anyvision", TRUE, TRUE, TRUE}});

	//line 10
		func = (OBJECT_CTOR.prototype.object.properties.find("hasOwnProperty")->second).value;
		printf("%d\n", ((has_own_property_func_t)func)(obj, (char *)"name"));
	}
	
	{
		void *func = NULL;
		
		object_t *shape1 = New();
		SHAPE_CTOR.ctor_func(shape1, (void *)"red");
		object_t *shape2 = New();
		SHAPE_CTOR.ctor_func(shape2, (void *)"green");
		
		printf("%d\n", InstanceOf(shape1, &SHAPE_CTOR));
		printf("%d\n", InstanceOf(shape1, &OBJECT_CTOR));
		
		printf("%d\n",shape1->proto->constructor == &SHAPE_CTOR);
		printf("%d\n",shape1->proto->constructor == &OBJECT_CTOR);
		
		SHAPE_CTOR.prototype.object.properties.insert(
					{"sayHi", {(void *)ShapeSayHi, TRUE, TRUE, TRUE}});
					
		func = (shape1->proto->object.properties.find("sayHi")->second).value;
		((shape_say_hi_func_t)func)(shape1);
		
		/*	TODO or not TODO that's the question
		 - 	func = getProperty(shape1, "toString");*/
		
		func = (shape1->proto->object.properties.find("toString")->second).value;
		/*	puts(((to_string_func_t)func)(shape1));*/
		
	}
	
	//Rectangle + Square
	{
		size_t rect1_dimentions[] = {5, 10};
		
		object_t *rectangle1 = New();
		RECTANGLE_CTOR.ctor_func(rectangle1, (void *)rect1_dimentions);
		
		void *func = (rectangle1->proto->object.properties.find("getArea")->second).value;
		printf("%lu\n",((rectangle_get_area_t)(func))(rectangle1));
		
		func = (rectangle1->proto->object.properties.find("toString")->second).value;
		puts(((to_string_func_t)func)(rectangle1));
		
		
		size_t square1_size = 6;
		object_t *square1 = New();
		SQUARE_CTOR.ctor_func(square1, (void *)&square1_size);
		
		func = (square1->proto->object.proto->object.properties.find("getArea")->second).value;
		printf("%lu\n", ((rectangle_get_area_t)func)(square1));
		
		func = (square1->proto->object.proto->object.properties.find("toString")->second).value;
		puts(((to_string_func_t)func)(square1));
		
		property_t name_property = {NULL, FALSE, FALSE, FALSE};
		func = (square1->proto->object.proto->object.proto->object.proto->object.properties.find("defineProperty")->second).value;
		((define_property_t)func)(square1, "name", name_property);
		
		func = (square1->proto->object.proto->object.proto->object.proto->object.properties.find("propertyIsEnumerable")->second).value;
		printf("%d\n", ((property_is_enumerable_t)func)(square1, "name"));
	}

	
	
	return 0;
}
