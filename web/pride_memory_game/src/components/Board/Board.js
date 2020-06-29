import React, {useCallback, useState} from "react";

import Card from "../Card/Card";
import {getRandomCards} from "../../config/initializeDeck";

const Board = ({handleFindMatch}) => {
    const [cards, setCards] = useState(getRandomCards)
    const [flippedCards, setFlippedCards] = useState([]);
    const [matchingCards, setMatchingCards] = useState([]);

    //TODO : add Reset button

    // const reset = () => {
    //     setMatchingCards([]);
    //     setFlippedCards([]);
    //     setCards(getRandomCards())
    // }

    const handleFlip = (name, show, hide) => {
        let length = flippedCards.length;

        if (length < 2) { //otherwise just 1 card is open
            console.log(length);
            show();
            const newElement = {name, hide};
            setFlippedCards([...flippedCards, newElement]);
            length = length + 1;

            if (length === 2) {
                if (flippedCards[0].name === name) {
                    handleFindMatch();
                    setMatchingCards([...matchingCards, name]);
                    setFlippedCards([]);
                } else {
                    setTimeout(() => {
                        flippedCards[0].hide();
                        hide();
                        setFlippedCards([]);
                    }, 1200);
                }
            }
        }
    }

    return (
        <div className='board'>
            {cards.map((card) =>
                <Card
                    className={'card'}
                    name={card.name}
                    cardImage={card.cardImage}
                    handleFlip={handleFlip}
                />
            )}
        </div>
    );
}

export default Board;