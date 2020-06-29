import React, {useCallback, useState} from "react";
import Card from "../Card/Card";
import {getRandomCards} from "../../config/initializeDeck";
// import '../Card/card.css'

const Board = ({handleFindMatch}) => {
    const [cards, setCards] = useState(getRandomCards)
    const [flippedCards, setFlippedCards] = useState([]);
    const [matchingCards, setMatchingCards] = useState([]);
    const [congrats, setCongrats] = useState(false)
    //
    // const reset = () => {
    //     setMatchingCards([]);
    //     setFlippedCards([]);
    //     setCards(getRandomCards())
    // }

    const countInArray = (array, value) => {
        return array.filter(element => element === value).length;
    }

    const handleFlip = (id) => {
        setFlippedCards([...flippedCards, id]);
        if (flippedCards.includes(id)) {
            setCongrats(true);
            handleFindMatch();
            setTimeout(() => {
                setCongrats(false)
            }, 1000);
        }
    }

    const handleBackFlip = (id) => {

        if (countInArray(flippedCards, id) === 2) {
            setMatchingCards([...matchingCards, id]);
            return false;
        } else {
            const index = flippedCards.indexOf(id);
            if (index > -1) flippedCards.splice(index, 1);
            console.log(`after modified ${flippedCards}`);

            return true;
        }
    }

        return (
            <div className='board'>

                {cards.map((card) =>
                    <Card
                        className={'card'}
                        id={card.id}
                        isFlipped={() => flippedCards.includes(card.id)}
                        cardImage={card.cardImage}
                        handleFlip={handleFlip}
                        handleBackFlip={handleBackFlip}
                    />
                )}
            </div>

        );

}
export default Board;