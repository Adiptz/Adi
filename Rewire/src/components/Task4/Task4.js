import React from "react";
import useClickCount from "../useClickCount";

const Task4 = ({Component}) => {
    const [count, increaseByOne] = useClickCount(0);

    return (
        <Component number={count} onClick={increaseByOne}/>
    );
}

export default Task4;