import React from "react";

const NumberDisplay = ({number, onClick}) => (
    <div className='number-display' onClick={onClick}>
        {number}
    </div>
);


export default NumberDisplay;