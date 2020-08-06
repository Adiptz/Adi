import React, {useState} from "react";
import factory from '../../images/2535.jpg'

const AchievementCard = ({title, value, currency}) => {

    if (currency) {
        let n = Number(value);
        value = n.toFixed(2);
    }

    return (
        <div className='achievement_card'>
            <h2>{title}</h2>
            <h4>{`${value} ${currency ? currency : ''}`}</h4>
            <img src={factory} alt='factory' height={'200px'} width={'300px'}/>
        </div>
    );
}

export default AchievementCard;