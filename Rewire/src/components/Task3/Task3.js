import React from "react";
import useClickCount from "../useClickCount";
import NumberDisplay from "../NumberDisplay/NumberDisplay";

const Task3 = () => {
    const [count, increaseByOne] = useClickCount(0);

    return (
        <NumberDisplay
            onClick={increaseByOne}
            number={count}
        />
    );
}

export default Task3;