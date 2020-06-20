import React, {useEffect, useState} from 'react';

import Recipe from "./Components/recipe/recipe";
import SearchBar from "./Components/search_bar/search_bar";
import './style/main.css';

//access to recipes API
const APP_ID = '51e14324';
const APP_KEY = '2c7f760533c8995fd5c6390476e2e696\t';

const App = () => {
    const [recipes, setRecipes] = useState([]);
    const [query, setQuery] = useState('banana');

    useEffect(() => {
        try {
            getRecipes();
        } catch (e) {
            console.log('err')
        }
    }, [query]);


    const getRecipes = async () => {
        const response = await fetch(`https://api.edamam.com/search?q=${query}&app_id=${APP_ID}&app_key=${APP_KEY}`,
            {
                mode: "cors"
            });
        const data = await response.json();
        setRecipes(data.hits);
    };

    const handleChange = value => {
        console.log(value);
        setQuery(value);
        getRecipes();
    }

    return (
        <div className="App">
            <h1 id='title'>Hungry?</h1>

            <SearchBar onSubmit={handleChange}/>

            <div className='recipes-container'>
                {recipes.map(recipe => (
                    <Recipe
                        key={recipe.recipe.uri}
                        title={recipe.recipe.label}
                        ingredients={recipe.recipe.ingredients}
                        calories={recipe.recipe.calories}
                        image={recipe.recipe.image}
                    />
                ))}
            </div>
        </div>
    );
};

export default App;
