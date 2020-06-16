vector_t *VectorCreate(size_t init_capacity, size_t size_of_elements)
{
	vector_t *new_vector = (vector_t*)malloc(sizeof(vector_t));
	if (new_vector == NULL)
	{
		return NULL;
	}
	
	new_vector->base = (void *)malloc(init_capacity * size_of_element);
	if (new_vector->base == NULL)
	{
		free(new_vector); new_vector = NULL;
		return NULL;
	}

	new_vector->current = new_vector->base;
	new_vector->capacity = init_capacity;
	new_vector->size_of_element = size_of_element;
}

void *VectorGetItemAddress(const vector_t *vector, size_t element_index)
{
	void *item_to_get = 
	(char *)vector->base + (element_index + vector->size_of_element);
	
	return item_to_get;

}

int VectorPushBack(vector_t *vector, const void *element_value)
{
	if (VectorSize(vector) == vector->capacity)
	{
		void *tmp = NULL;
		size_t current_size = VectorSize(vector);		
				
		vevctor->capacity *= 2;
		
		tmp = realloc(vector->base, vector->capacity * vector->size_of_element);
		if (tmp == NULL)
		{
			return NULL;
		}
		
		vector->base = tmp;
		vector->current = (char *)vector->base +
						  (current_size * vector->size_of_element);
	}
	
	memcpy(vector->current, element_value, vector->size_of_element);
	vector->current = (char *)vector->current + vector->size_of_element;	
		
	}

}



int VectorPopBack(vector_t *vector)
{
	size_t current_size = 0;
	
	current_size = VectorSize(vector);
	vector->current = (char *)vector->current - vector->size_of_element;
	--current_size;
	
	if (current-size <= vetor->capacity / 4)
	{
		void *tmp = realloc(vector->base, ((vector->capacity / 2) * 
											vector->size_of_element);
		if (NULL == tmp)
		{
			return FAIL;
		}
		
		vector->base = tmp;
		vector->current = (char *)vector->base + current_size);
		vector->capacity /= 2;
	}
	
	return SUCCESS;	
}
	
int VectorReserve(vector_t *vector, size_t size)
{
	size_t current_size = 0;
	void *tmp = NULL;
	
	assert(NULL != vector); 
	
	current_size = VectorSize(vector);
	
	tmp = realloc(vector->base, vector->capacity + size);
	if (NULL == tmp)
	{
		return 1;
	}
	
	vector->base = tmp;
	vector->curret = (char *)vector->base + current_size;
	vector->capacity += size;
	
	return 0;
}
















}



