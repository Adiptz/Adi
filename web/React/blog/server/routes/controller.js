const login_check = require('./login_check');
const cors = require('cors');
const express = require('express');
const cookieParser = require('cookie-parser');

const userService = require('../services/user-service');
const postsModel = require('../models/posts');
const sessionModel = require('../models/sessions');

const app = express();
app.use(express.json());

app.use(cors({
  origin: 'http://localhost:3000',
  credentials: true,
}));

app.use(cookieParser());

// /users
app.post('/users', (req, res) => {
  const { first_name, last_name, password, email } = req.body;
  userService.signUp(first_name, last_name, password, email);

  res.end();
});

//sign in
app.post('/signin', async (req, res) => {


  const { email, password } = req.body;

  let isConfirm = await userService.signIn(email, password);

  if (isConfirm) {
    console.log('confirmed');
    const randToken = Math.random().toString(36).substring(2);
    res.cookie('token', `${randToken}`, { maxAge: 93500000,
    httpOnly: true});
    await sessionModel.setSession(randToken, email);
  } else {
    console.log('no')
    res.writeHead(400);
  }
  res.end();
});

//app.use(login_check.isLogin); // user should be connect for next actions

//posts
app.post('/posts', async (req, res) => {
  const { title, body } = req.body;

  const user_id = req.logInUser;
  await postsModel.savePost(title, body, user_id);
});

app.get('/posts', async (req, res) => {
  const user_id = 9; //req.logInUser;
  const posts = await postsModel.getUserPosts(user_id);
  res.send(posts);
});

app.listen(8080);
console.log('server is running on http://localhost:8080');
