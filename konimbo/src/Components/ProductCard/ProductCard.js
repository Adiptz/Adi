import React, {useState} from "react";
import ProductPage from "../ProductPage/ProductPage";

const ProductCard = (props) => {
    const {title, mainImage, price, images, store_category_title} = props;
    const [showProductPage, setShowProductPage] = useState(false);

    let newPrice = parseInt(price);
    let i = 0;

    const handleClose = () => {
        setShowProductPage(false);
    }

    if (showProductPage) {
        return (
            <ProductPage
                handleClose={handleClose}
                category={store_category_title}
                images={images}
                price={price}
                title={title}
                key={i++}

            />
        );
    }

    return (
        <div className='product' onClick={() => setShowProductPage(true)}>
            {showProductPage ?
                <ProductPage
                    images={images}
                    price={price}
                    title={title}
                    category={store_category_title}
                    key={i++}
                /> : null}
            <h3>{title}</h3>
            <p>{`price : ${newPrice}`}</p>
            <img src={mainImage} alt=""/>
        </div>
    );
};

export default ProductCard;