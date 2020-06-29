import React, {useState} from "react";
import ReactCardFlip from 'react-card-flip';
import pride from '../../images/pride.jpg'


const Card = ({cardImage, id, handleFlip, handleBackFlip}) => {
    const [isFlipped, setIsFlipped] = useState(false);

    return (
        <ReactCardFlip
            isFlipped={isFlipped}
            flipDirection="vertical">

            <div key="front" className={'front'}>
                <img
                    alt={'pride_month'}
                    src={pride}
                    onClick={() => {
                        setIsFlipped(true);
                        handleFlip(id);
                    }}/>
            </div>

            <div key="back" className={'back'}>
                <img
                    alt={'gay_influence_character'}
                    src={require(`../../images/${cardImage}`)}
                    onClick={() => {
                        let shouldFlipBack = handleBackFlip(id);
                        if (shouldFlipBack) setIsFlipped(false);
                    }}
                />
            </div>
        </ReactCardFlip>
    )
}

export default Card;
