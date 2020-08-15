// implement custom Hook - Task 3
import {useState} from "react";

const useClickCount = initialState => {
    const [count, setCount] = useState(initialState);
    const increaseByOne = () => setCount(prevState => prevState + 1);

    return [count, increaseByOne];
}

export default useClickCount;