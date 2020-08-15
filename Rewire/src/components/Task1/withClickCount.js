import React, {Component} from "react";

// Higher-Order Component
const withClickCount = OriginalComponent => {
    class NewComponent extends Component {
        constructor(props) {
            super(props);
            this.state = {
                number: 0
            };
        }

        increaseByOne = () => {
            this.setState(prevState => ({number: prevState.number + 1}));
        }

        render() {
            return (
                <OriginalComponent
                    number={this.state.number}
                    onClick={this.increaseByOne}
                />
            )
        }
    }

    return NewComponent;
}

export default withClickCount;