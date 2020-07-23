import React, {useEffect, useState} from "react";
import ProductCard from "../ProductCard/ProductCard";
import SearchBar from "../SearchBar/SearchBar";

const ProductsBoard = () => {

    const [ind, setInd] = useState(0);
    const [products, setProducts] = useState([]);
    const [searchRegex, setSearchRegex] = useState('');
    const [searchedProducts, setSearchedProducts] = useState([]);
    const [displayedProducts, setDisplayedProducts] = useState([]);


    let key = 0;

    useEffect(() => {
        try {
            getProducts().then(data => {
                setProducts(data);
                setDisplayedProducts(data.slice(ind, ind + 12));

            });
        } catch (e) {
            console.log('err')
        }
    }, []);

    const getProducts = async () => {
        const url = 'https://api.konimbo.co.il/v1/items?token=9c1a92bf8cefc59e4ec9fa7c53bba0f90dd8b15850bef1062dbf32c5e8fd3a08';
        const response = await fetch(url);
        return await response.json();
    };

    const handleSearch = (regex) => {
        if (regex === '') {
            setSearchedProducts([]);
        } else {
            setSearchRegex(regex);
            console.log(`regex : ${regex}`);
            const regex_input = new RegExp(regex, 'ig');
            const searchResult = products.filter(({title, store_category_title}) => regex_input.test(title) || regex_input.test(store_category_title));
            setSearchedProducts(searchResult);
        }
    }

    const prevProducts = () => {
        const newIndex = ind - 12;
        setDisplayedProducts(products.slice(newIndex, newIndex + 12));
        setInd(newIndex);
    }
    const nextProducts = () => {
        const newIndex = ind + 12;
        setDisplayedProducts(products.slice(newIndex, newIndex + 12))
        setInd(newIndex);
    }

    return (
        <div>
            <SearchBar onSearch={handleSearch}/>

            <div className='products-container'>
                {
                    searchedProducts.length === 0
                    ?
                    displayedProducts.map(product => (
                        <ProductCard
                            title={product?.title}
                            price={product?.price}
                            images={product?.images}
                            mainImage={product?.images[0]?.url}
                            key={key++}
                        />
                    ))
                    :
                    searchedProducts.map(product => (
                        <ProductCard
                            title={product?.title}
                            price={product?.price}
                            images={product?.images}
                            mainImage={product?.images[0]?.url}
                            key={key++}
                        />))}
            </div>


            < div className='nav-buttons'>
                <button className='move-page' onClick={prevProducts}>Back</button>
                <button className='move-page' onClick={nextProducts}>Next</button>
            </div>
        </div>
    );
}

export default ProductsBoard;