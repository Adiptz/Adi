import Card from "../components/Card/Card";
import React from "react";
import shuffle from "../utils/utils";

let initializeDeck = [
    {   id: 1,
        cardImage: 'spongebob.png' },
    {   id: 1,
        cardImage: 'spongebob.png' },
    {   id: 2,
        cardImage: 'ofra.webp' },
    {   id: 2,
        cardImage: 'ofra.webp' },
    {   id: 3,
        cardImage: 'ellen.jpg' },
    {   id: 3,
        cardImage: 'ellen.jpg' },
    {   id: 4,
        cardImage: 'dana.jpg' },
    {   id: 4,
        cardImage: 'dana.jpg' },
    {   id: 5,
        cardImage: 'rupaul.png' },
    {   id: 5,
        cardImage: 'rupaul.png' },
    {   id: 6,
        cardImage: 'alan.jpg' },
    {   id: 6,
        cardImage: 'alan.jpg' },
];

export const numOfCards = initializeDeck.length;

export const getRandomCards= () => {
    return shuffle(initializeDeck);
}

// export default getRandomCards() ;

