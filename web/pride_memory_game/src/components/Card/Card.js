import React, {useState} from "react";
import ReactCardFlip from 'react-card-flip';
import pride from '../../images/pride.jpg'


const Card = ({name, cardImage, handleFlip, handleBackFlip}) => {
    const [isVisible, setIsVisible] = useState(false);

    const show = () => {
        setIsVisible(true);
    }

    const hide = () => {
        setIsVisible(false);
    }

    return (
        <ReactCardFlip
            isFlipped={isVisible}
            flipDirection="vertical">

            <div key="front" className={`front`}>
                <img
                    alt={'pride_month'}
                    src={pride}
                    onClick={() => handleFlip(name, show, hide)}/>
            </div>

            <div key="back" className={`back`}>
                <img
                    alt={'gay_character'}
                    src={require(`../../images/${cardImage}`)}
                />
            </div>
        </ReactCardFlip>
    )
}

export default Card;

