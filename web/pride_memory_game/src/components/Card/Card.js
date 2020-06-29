import React, {useState} from "react";
import ReactCardFlip from 'react-card-flip';
import pride from '../../images/pride.jpg'


const Card = ({cardImage, id, handleFlip, handleBackFlip}) => {
    const [isVisible, setIsVisible] = useState(false);

    const show = () => {
        setIsVisible(true);
        let isMatch = handleFlip(id);
        if (isMatch === false) {
            setIsVisible(false);
        }
    }

    const hide = () => {
            let shouldClose = handleBackFlip(id);
            if (shouldClose) setIsVisible(false);
    }

    return (
        <ReactCardFlip
            isFlipped={isVisible}
            flipDirection="vertical">

            <div key="front" className={`front`}>
                <img
                    alt={'pride_month'}
                    src={pride}
                    onClick={show}/>
            </div>

            <div key="back" className={`back`}>
                <img
                    alt={'gay_character'}
                    src={require(`../../images/${cardImage}`)}
                    onClick={hide}
                />
            </div>
        </ReactCardFlip>
    )
}

export default Card;

