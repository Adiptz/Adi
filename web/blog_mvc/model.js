import {getElement, createElement} from "./utils.js";

class Model {
    constructor() {
        this.posts = JSON.parse(localStorage.getItem("posts")) || [];
    }

    updatePosts() {
        localStorage.setItem("posts", JSON.stringify(this.posts));
    }

    bindAddPost(event) {
        this.onAddPost = event;
    }

    addPost(newPost) {
        this.posts.unshift(newPost);
        this.updatePosts();
        this.onAddPost(newPost);
    }

    getPosts() {
        return localStorage.getItem('posts');
    }

    searchPosts(input) {
        const regex_input = new RegExp(input, 'ig');
        return this.posts.filter(({title, body}) => regex_input.test(title) || regex_input.test(body));
    }
}
export default Model;

