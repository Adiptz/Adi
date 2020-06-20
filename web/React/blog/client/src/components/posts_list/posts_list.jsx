import React from 'react'
import axios from 'axios'


import Post from './post/post';


import './posts_list.css'

class PostsList extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      posts: []
    }
  }

  componentDidMount() {
    axios.get('http://localhost:8080/posts')
      .then(res => {
        this.setState({ posts: res.data })
      })
  }

  render() {
    const { posts } = this.state;

    return (
      <div className="posts_list">
        {
          posts.length ?
            posts.map(post => <Post
              title={post.post_title}
              content={post.post_body}/>) :
            null
        }
      </div>
    );
  }
}

export default PostsList