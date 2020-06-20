import React, {useState} from 'react';
import './style/calculator.css'
import './style/display.css'
import './style/keypad.css'
import './App.css';

import Display from "./Components/Display";
import KeyPad from "./Components/KeyPad";

function App() {
  const [result, setResult] = useState('');

  const calculate = () => {
    try {
      const noLeadingZero = result.replace(/^0+/, '');
      setResult(noLeadingZero);
      setResult(eval(noLeadingZero));
    }  catch (e){
      setResult('Err');
      console.log(e);
    }
  }

  const onClick = name => {

    if (name === '=') {
      calculate();
    }
    else if (name === 'C') {
      setResult('');
    }
    else {
      setResult(result + name);
    }
  }

  return (
    <div className="calculator-body">
    <Display className='result' result={result}/>
    <KeyPad className='keypad' onClick={onClick}/>
    </div>
  );
}

export default App;
