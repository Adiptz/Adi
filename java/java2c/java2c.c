
#include <stdio.h> /* puts, printf, sprintf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcpy, strcat */

#define UNUSED(x) ((void)(x))

/************************** -- -- ************************/
int counter = 0;
enum created_classes {FALSE, TRUE};

typedef void *(*v_func_t)(void *);
typedef struct Metadata Metadata_t;

/******************************* -- Structs -- ********************************/
struct Metadata 
{
	char *name;
	size_t size;
	Metadata_t *super_metadata;
	v_func_t *methods;
};

typedef struct Object
{
	Metadata_t *metadata;
} Object_t;

typedef struct Animal 
{
	Object_t super;
	int ID;
	int num_legs;
	int num_masters;
} Animal_t;

typedef struct Dog
{
	Animal_t super;
	int num_legs;
} Dog_t;

typedef struct Cat
{
	Animal_t super;
	char *color;
	int num_masters;
} Cat_t;

typedef struct Legendary
{
	Cat_t super;
} Legendary_t;

/****************************** -- v funcs -- *********************************/

void ObjectFinalize(Object_t *this);
void AnimalFinalize(Object_t *this);
void DogFinalize(Object_t *this);
void CatFinalize(Object_t *this);
void LegendaryFinalize(Object_t *this);

char global_buff[50];
					   
/****** -- To String -- ******/
char *ObjectToString(Object_t *this)
{
	return this->metadata->name;
}

char *AnimalToString(Animal_t *this)
{
	sprintf(global_buff, "Animal with ID : %d", this->ID);
	
	return global_buff;
}
char *DogToString(Dog_t *this)
{
	sprintf(global_buff, "Dog with ID : %d", this->super.ID);
	
	return global_buff;
}

char *CatToString(Cat_t *this)
{
	sprintf(global_buff, "Cat with ID : %d", this->super.ID);
	
	return global_buff;
}

char *LegendaryToString(Legendary_t *this)
{
	sprintf(global_buff, "Legendary with ID : %d", this->super.super.ID);
	
	return global_buff;
}

/****** -- Say Hello -- ******/
void AnimalSayHello(Animal_t *this)
{
	printf("Animal Hello!\nI have %d legs\n", this->num_legs);
}

void DogSayHello(Dog_t *this)
{
	printf("Dog Hello!\nI have %d legs\n", this->num_legs);
}

void LegendarySayHello(Legendary_t *this)
{
	UNUSED(this);
	puts("Legendary Hello!");
}

/****** -- Show Counter -- ******/
void AnimalShowCounter(Animal_t *this)
{
	UNUSED(this);
	printf("%d\n", counter);
}

/***** -- Get Num Masters -- *****/
int AnimalGetNumMasters(Animal_t *this)
{
	return this->num_masters;
}


					   
/**************************** -- v func tables -- *****************************/
enum methods_position {TO_STRING,
					   FINALIZE,
					   SAY_HELLO,
					   SHOW_COUNTER,
					   GET_NUM_MASTERS};


					   
v_func_t obj_v_table[] = {(v_func_t)ObjectToString,
						  (v_func_t)ObjectFinalize}; 
						  
v_func_t animal_v_table[] = {(v_func_t)AnimalToString,
							 (v_func_t)AnimalFinalize,
							 (v_func_t)AnimalSayHello,
							 (v_func_t)AnimalShowCounter,
							 (v_func_t)AnimalGetNumMasters};
							 
v_func_t dog_v_table[] = {(v_func_t)DogToString,
						  (v_func_t)DogFinalize,
					      (v_func_t)DogSayHello,
					      (v_func_t)AnimalShowCounter,
					      (v_func_t)AnimalGetNumMasters};

v_func_t cat_v_table[] = {(v_func_t)CatToString,
						  (v_func_t)CatFinalize,
						  (v_func_t)AnimalSayHello,
						  (v_func_t)AnimalShowCounter,
						  (v_func_t)AnimalGetNumMasters};
						  
v_func_t legendary_v_table[] = {(v_func_t)LegendaryToString,
								(v_func_t)LegendaryFinalize,
								(v_func_t)LegendarySayHello,
								(v_func_t)AnimalShowCounter,
								(v_func_t)AnimalGetNumMasters};


/******** -- Finalize -- ********/
void ObjectFinalize(Object_t *this)
{
	UNUSED(this);
	/* empty body */
}

void AnimalFinalize(Object_t *this)
{
	printf("finalize Animal with ID: %d\n", ((Animal_t *)this)->ID);
	obj_v_table[FINALIZE](this);
}

void DogFinalize(Object_t *this)
{
	printf("finalize Dog with ID: %d\n", ((Animal_t *)this)->ID);
	animal_v_table[FINALIZE](this);
}

void CatFinalize(Object_t *this)
{
	printf("finalize Cat with ID: %d\n", ((Animal_t *)this)->ID);
	animal_v_table[FINALIZE](this);
}

void LegendaryFinalize(Object_t *this)
{
	printf("finalize LegendaryAnimal with ID: %d\n", ((Animal_t *)this)->ID);
	cat_v_table[FINALIZE](this);
}

/******************************* -- Metadata -- *******************************/
Metadata_t obj_metadata = {"Object", sizeof(Object_t), NULL, obj_v_table}; 

Metadata_t animal_metadata = {"Animal",sizeof(Animal_t),
							  &obj_metadata, animal_v_table};

Metadata_t dog_metadata = {"Dog", sizeof(Dog_t), &animal_metadata, dog_v_table};

Metadata_t cat_metadata = {"Cat", sizeof(Cat_t), &animal_metadata, cat_v_table};

Metadata_t legendary_metadata = {"Legendary", sizeof(Legendary_t),
								 &cat_metadata, legendary_v_table};

/********************************* -- Init -- *********************************/
void *Init(Metadata_t *metadata)
{
	void *this = (void *)malloc(metadata->size);
	((Object_t *)this)->metadata = metadata;
	
	return this;
}


/********************** -- Static Initalize Blocks -- *************************/
void AnimalStaticInit()
{
	static int animal_created = FALSE;
	
	if (!animal_created)
	{
		puts("Static block Animal 1\nStatic block Animal 2");
		animal_created = TRUE;
	}	
}

void DogStaticInit()
{
	static int dog_created = FALSE;
	
	if (!dog_created)
	{
		AnimalStaticInit();
		puts("Static block Dog");
		dog_created = TRUE;
	}	
}

void CatStaticInit()
{
	static int cat_created = FALSE;
	
	if (!cat_created)
	{
		AnimalStaticInit();
		puts("Static block Cat");
		cat_created = TRUE;
	}	
}


void LegendaryStaticInit()
{
	static int legendary_created = FALSE;
	
	if (!legendary_created)
	{
		CatStaticInit();
		puts("Static block Legendary Animal");
		legendary_created = TRUE;
	}

}

/*************************** -- Constructors -- *******************************/
/***** -- Obj -- ******/
void ObjConstructor(Object_t *this)
{
	UNUSED(this);
	/* do nothing */;
}

/******* -- Animal -- *******/
void AnimalConstrucor(Animal_t *this)
{
	AnimalStaticInit();
	ObjConstructor((Object_t *)this);
	this->num_legs = 5;
	this->num_masters = 1;
	puts("Instance initialization block Animal"); 
	puts("Animal Ctor");
	this->ID = ++counter;
	((Object_t *)this)->metadata->methods[SAY_HELLO](this);
 	AnimalShowCounter(this);
	printf("%s\n", (char *)((Object_t *)this)->metadata->methods[TO_STRING](this));
    printf("%s\n", (char *)obj_v_table[TO_STRING](this));
}

void AnimalConstrucor2(Animal_t *this, int num_masters)
{
	AnimalStaticInit();
	ObjConstructor(&this->super);
	this->ID = ++counter;
	this->num_legs = 5;
	this->num_masters = num_masters;
	puts("Instance initialization block Animal");
	puts("Animal Ctor int");
}

/***** -- Dog -- ******/
void DogConstructor(Dog_t *this)
{
	DogStaticInit();
	AnimalConstrucor2((Animal_t *)&this->super, 2);
	this->num_legs = 4;
	puts("Instance initialization block Dog");
	puts("Dog Ctor");
}

/***** -- Cat -- ******/
void CatConstructor2(Cat_t *this, char *color)
{
	CatStaticInit();
	AnimalConstrucor((Animal_t *)&this->super);
	this->color = color;
	this->num_masters = 2;
	printf("Cat Ctor with color: %s\n", color);
}

void CatConstructor(Cat_t *this)
{
	CatConstructor2(this, "black");
	puts("Cat Ctor");
}

void LegendaryConstructor(Legendary_t *this)
{
	LegendaryStaticInit();
	CatConstructor((Cat_t *)this);
	puts("Legendary Ctor");
}


/********************* -- foo -- ***********************/
void foo(Animal_t *this)
{
	printf("%s\n", (char *)(this->super.metadata->methods[TO_STRING](this)));
}

/************************* -- main -- ***********************/
int main()
{
	/** -- arr Decleration -- **/
	size_t i = 0;
	#define ARR_SIZE 5
	Animal_t *Animal[ARR_SIZE];

	/** -- Objects Declerations -- **/
	Animal_t *animal = NULL;
	Dog_t *dog = NULL;
	Cat_t *cat = NULL;
	Legendary_t *legendary = NULL;
	
	
	/** -- Objects Constructors -- **/
	animal = (Animal_t *)Init(&animal_metadata);
	AnimalConstrucor(animal);
	puts("");
	
	dog = (Dog_t *)Init(&dog_metadata);
	DogConstructor(dog);
	puts("");

	cat = (Cat_t *)Init(&cat_metadata);
	CatConstructor(cat);
	puts("");

	legendary = (Legendary_t *)Init(&legendary_metadata);
	LegendaryConstructor(legendary);
	puts("");

	/** -- some printings --**/
	animal_v_table[SHOW_COUNTER](animal);
	printf("%d\n",animal->ID);
	printf("%d\n", ((Animal_t *)dog)->ID);
	printf("%d\n", ((Animal_t *)cat)->ID);
	printf("%d\n", ((Animal_t *)legendary)->ID);
	

	{
		/** -- array Animal[] Objects Declerations -- **/
		
		Dog_t *dog_arr = NULL;
		Cat_t *cat_arr = NULL;
		Cat_t *white_cat_arr = NULL;
		Legendary_t *legendary_arr = NULL;
		Animal_t *animal_arr = NULL;
		/** -- array Objects Constructors -- **/
		dog_arr = (Dog_t *)Init(&dog_metadata);
		DogConstructor(dog_arr);
		puts("");

		cat_arr = (Cat_t *)Init(&cat_metadata);
		CatConstructor(cat_arr);
		puts("");

		white_cat_arr = (Cat_t *)Init(&cat_metadata);
		CatConstructor2(white_cat_arr, "white");
		puts("");

		legendary_arr = (Legendary_t *)Init(&legendary_metadata);
		LegendaryConstructor(legendary_arr);
		puts("");
		
		animal_arr = (Animal_t *)Init(&animal_metadata);
		AnimalConstrucor(animal_arr);
		puts("");

		/* array Animal[] */
		Animal[0] = (Animal_t *)dog_arr;
		Animal[1] = (Animal_t *)cat_arr;
		Animal[2] = (Animal_t *)white_cat_arr;
		Animal[3] = (Animal_t *)legendary_arr;
		Animal[4] = (Animal_t *)animal_arr;
		
		for (i = 0; i < ARR_SIZE; ++i)
		{
			Animal[i]->super.metadata->methods[SAY_HELLO](Animal[i]);
			printf("%d\n",(Animal[i]->super.metadata->methods[GET_NUM_MASTERS](Animal[i])));
		}
		
		for (i = 0; i < ARR_SIZE; ++i)
		{
			foo(Animal[i]);
		}
		
		puts("");
		
		/* Finalize All array*/
		for (i = ARR_SIZE; 0 < i; --i)
		{
			Animal[i - 1]->super.metadata->methods[FINALIZE](Animal[i - 1]);
		}

		/* Finalize Remains */
		legendary_v_table[FINALIZE](legendary);
		cat_v_table[FINALIZE](cat);
		dog_v_table[FINALIZE](dog);
		animal_v_table[FINALIZE](animal);
	}
	
	printf("\033[1;31m");
	printf("\nVOVA THE QUEEN - VOVA THE QUEEN - VOVA THE QUEEN - VOVA THE QUEEN \n");

	return 0;
}
