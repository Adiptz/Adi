import React, {useState} from "react";

const ProductPage = ({title, price, images, handleClose}) => {

    let i = 0;
    const [mainImage, setMainImage] = useState(images[0]?.url);
    const [galleryImages, setGalleryImages] = useState(images.slice(0, 9))

    const priceNoDot = parseInt(price);
    return (
        <div className='black-layout'>
            <div className='product-page'>
                <button className='close-page' onClick={handleClose}>X</button>
                <h1>{title}</h1>
                <img id='main-image' src={mainImage} alt=''/>
                <div className='gallery'>
                    {galleryImages.map((image) => (
                        <img className='gallery-pic'
                             src={image?.url}
                             alt=''
                             onClick={() => setMainImage(image?.url)}
                             key={i++}
                        />))
                    }
                </div>

                <div className='product-details'>
                    <h2>Price : {priceNoDot} </h2>
                </div>

                <div className='product-buttons'>
                <button className='order-button'>Order Now!</button>
                <button className='addToCart-button'>Add to cart</button>
                </div>
            </div>
        </div>
    );
}

export default ProductPage;