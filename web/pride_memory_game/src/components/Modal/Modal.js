import React, {useState} from 'react';
import Rodal from 'rodal';

// include styles
const Modal = ({content, hidden, headline}) => {
    const [visible, setVisible] = useState(true);

    const show = () => {
        setVisible(true);
    }

    const hide = () => {
        setVisible(false)
    }

    const instructions = `Turn over any two cards. \n
                          Found match? great! \n
                          If not - flip them over. \n
                          The game is over when all the cards have been matched.`;



    const breakText = (text) => {
        return text.split('\n').map((item, i) => <p key={i}>{item}</p>);
    }


    return (
        <div>

            <Rodal visible={visible} onClose={hide}>
                <p className={'headline rainbow-text'}>{headline}</p>

                <p className={'modal-content'}>
                    {content === 'instructions' ?
                        breakText(instructions) :
                      ''}
                </p>
                <button
                    className={`rainbow rainbow-1 ${hidden === true ? 'hidden' : ''}`}
                    onClick={() => {
                        hide();
                    }}
                >
                    Start Game
                </button>
            </Rodal>
        </div>
    );

}
export default Modal;
