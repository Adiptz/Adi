import React from 'react'

import './login.css'
import { withRouter } from 'react-router';

import {
  Redirect,
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from 'react-router-dom';

import axios from 'axios';

class LoginPage extends React.Component {

  constructor(props) {
    super(props);

    this.state = {
      email: '',
      password: '',
      validate : true
    };

    this.signIn = this.signIn.bind(this);
    this.handleEmailChange = this.handleEmailChange.bind(this);
    this.handlePasswordChange = this.handlePasswordChange.bind(this);
  }

  signIn(e) {
    e.preventDefault();

    axios.post('http://localhost:8080/signin',
      {
        email: this.state.email,
        password: this.state.password
      },

      { withCredentials: true }
    )
      .then(response => {
        if (response.status === 200) {
          console.log(response)
          this.props.history.push('/feed');
        }})
      .catch(response =>  {
        this.setState({validate : false})
    })

  }

  handleEmailChange(event) {
    this.setState({
      email: event.target.value,
      password: this.state.password
    });
  }

  handlePasswordChange(event) {
    this.setState({
      email: this.state.email,
      password: event.target.value
    });
  }


  render() {
    let err;

    if (!this.state.validate) {
      err = <span>GOOD</span>
    }
    return (

      <form className="sign-in-form" onSubmit={this.signIn}>
        {err}
        <h2 className='sign_in_title'>Sign In</h2>

        <p>
          <input
            id="email_signin"
            name="email"
            type="text"
            placeholder="Email Address"
            autoComplete='off'
            required="required"
            onChange={this.handleEmailChange}
          />
        </p>

        <p>
          <input
            id="password_signin"
            name="password"
            type="password"
            placeholder="Password"
            required="required"
            onChange={this.handlePasswordChange}
          />
        </p>

        <button
          type='submit'
          id="sign-in"
        >
          SIGN IN
        </button>
        <br/>

        <Link className="change_link" to='/signup'>
          Not a member yet ? Sign Up!
        </Link>
      </form>

    );
  };


}

export default withRouter(LoginPage)



