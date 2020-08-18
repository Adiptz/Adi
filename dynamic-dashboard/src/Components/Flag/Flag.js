import React from "react";
import {Rnd} from "react-rnd";

const Flag = ({country, title}) => {
    const {name, averageClassSize, averageAnnualWages} = country;

    return (
            <Rnd default={{x: 300, y: 200}}>
                <h3>{title}</h3>
                <img className='flag-image' src={require(`../../images/flags/${name}.jpg`)} alt='flag'/>
                <h4>{name}: {averageClassSize} {averageAnnualWages}</h4>
            </Rnd>
    )
}

export default Flag;