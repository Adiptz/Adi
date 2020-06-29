import React, { useState} from 'react';
import Board from './components/Board/Board';
import Counter from "./components/Counter/Counter";
import Modal from "./components/Modal/Modal";
import '../src/styles/main.css';

function App() {
let [counterMatchPair, setCounterMatchPair] = useState(0);

const handleFindMatch = () => {
    setCounterMatchPair(++counterMatchPair);
}
    return (
        <div className="App">
            <Modal
                headline={'Welcome!'}
                content={'instructions'}
            />
            <h1 className='happy-pride-month'>Happy Pride Month!</h1>
            <Board handleFindMatch={handleFindMatch}/>
            <Counter count={counterMatchPair}/>
        </div>
    );

}

export default App;
