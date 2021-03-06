import React from "react";
import {numOfCards} from '../../config/initializeDeck'
import Modal from "../Modal/Modal";

const Counter = ({count}) => {
    const isDone = (count === numOfCards / 2);
    if (isDone) {
        return (
            <Modal hidden={true} headline={'Thanks For Playing!'}/>
        );
    } else return (
        <h2 className={'counter'}><span>{count}</span> <br/> matches</h2>
    );
}

export default Counter;