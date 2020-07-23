import React from 'react';
import './style/main.css'
import ProductsBoard from "./Components/ProductsBoard/ProductsBoard";
import Header from "./Components/Header/Header";

function App() {
    return (
        <div className='App'>
            <Header/>
            <ProductsBoard/>
        </div>
    );
}

export default App;
