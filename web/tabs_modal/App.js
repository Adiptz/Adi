import React, {useState} from 'react';
import './App.css';

import ModalWithTabs from "./components/Modal";

function App() {
    const [isShow, setIsShow] = useState(false);
    let ToRender;
    if (isShow) {
        ToRender = <ModalWithTabs/>;
    } else {
        ToRender = <button className='advanced-button' onClick={() => setIsShow(isShow => !isShow)}>Advanced</button> ;
    }
    return (
        <>
        {ToRender}
        </>
    );
}


export default App;
