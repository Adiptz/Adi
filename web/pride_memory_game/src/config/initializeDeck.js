import Card from "../components/Card/Card";
import React from "react";
import shuffle from "../utils/utils";

let initializeDeck = [
    {   id: 1,
        name: 'spongebob',
        cardImage: 'spongebob.png' },
    {   id: 1,
        name: 'spongebob',
        cardImage: 'spongebob.png' },
    {   id: 2,
        name: 'ofra',
        cardImage: 'ofra.jpg' },
    {   id: 2,
        name: 'ofra',
        cardImage: 'ofra.jpg' },
    {   id: 3,
        name: 'ellen',
        cardImage: 'ellen.jpg' },
    {   id: 3,
        name: 'ellen',
        cardImage: 'ellen.jpg' },
    {   id: 4,
        name: 'dana',
        cardImage: 'dana.jpg' },
    {   id: 4,
        name: 'dana',
        cardImage: 'dana.jpg' },
    {   id: 5,
        name: 'rupaul',
        cardImage: 'rupaul.png' },
    {   id: 5,
        name: 'rupaul',
        cardImage: 'rupaul.png' },
    {   id: 6,
        name: 'alan',
        cardImage: 'alan.jpg' },
    {   id: 6,
        name: 'alan',
        cardImage: 'alan.jpg' },
];

export const numOfCards = initializeDeck.length;

export const getRandomCards= () => {
    return shuffle(initializeDeck);
}

// export default getRandomCards() ;

