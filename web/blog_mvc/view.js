import {getElement, debounce} from "./utils.js";
import newBoxModule from "./modules/create_post.js";

class View {
    constructor() {
        // Initialize Elements
        this.postBody = getElement('#body_new_post');
        this.postTitle = getElement('#title_new_post');
        this.publishButton = getElement('#publish_button');
        this.plusButton = getElement('#add_button');
        this.userSearch = getElement('#user_search');
        this.postsContainer = getElement('#all_posts');

        // Event Listeners
        this.plusButton.addEventListener('click', () => {
            _openModal();
        });

        window.addEventListener('load', () => {
            const postsFromStorage = this.getPosts();

            if (postsFromStorage) {
                _displayAllPosts(postsFromStorage);
            }
        });

        document.addEventListener('keydown', (event) => {
            if (event.code === 'Escape') {
               _closeModal();
            }
        });
    }

    bindGetPosts(handleGetPosts) {
        this.getPosts = handleGetPosts;
    }

    bindSearch(handleSearch) {
        this.userSearch.addEventListener('keyup', event => {
            _removeAllPosts();
            const input = this.userSearch.value;
            console.log(input);
            const arrFoundPosts = handleSearch(input);
            _displayFoundPosts(arrFoundPosts, input);
        });
    }

    bindAddPost(handleAddPost) {
        this.publishButton.addEventListener('click', event => {
            event.preventDefault();

            //get input from modal
            const title = this.postTitle.value;
            const body = this.postBody.value;
            const newPost = {title, body};

            handleAddPost(newPost);
            _closeModal();
        });
    }

    addPost(newPost) {
        const postContainer = getElement('#all_posts');
        const article = newBoxModule.createNewPost(newPost);
        postContainer.insertBefore(article, postContainer.firstChild);
    }

}
export default View;



// Modal
function _openModal() {
    getElement('#all_posts').className = 'hidden_class';
    getElement('#hidden_black_cover').id = 'black_cover';
    getElement('#hidden_edit_new_post').id = 'edit_new_post';
}


function _cleanModalFields() {
    //clean fields for the next use
    getElement('#title_new_post').value = "";
    getElement('#body_new_post').value = "";
}

function _closeModal() {
    getElement('#edit_new_post').id= 'hidden_edit_new_post';
    getElement('#all_posts').className = 'shown_class';
    getElement('#black_cover').id = 'hidden_black_cover';
    _cleanModalFields();
}

// Posts
function _displayAllPosts(postsFromStorage) {

    const postsArr = JSON.parse(postsFromStorage);

    for (const post of postsArr) {

        const title = post.title;
        const body = post.body;

        const article = newBoxModule.createNewPost({title, body});
        _appendArticle(article);
    }
}

function _appendArticle(article) {
    document.getElementById("all_posts").appendChild(article);
}

function _displayFoundPosts(foundPosts, inputSearched) {

    foundPosts.forEach(post => {
        const {title, body} = post;
        const article = newBoxModule.createNewPost(post);
        getElement('#all_posts').appendChild(article);

        const titleBox = article.children[0];
        titleBox.innerHTML = _markString(title, inputSearched);

        const bodyBox = article.children[1];
        bodyBox.innerHTML = _markString(body, inputSearched);
    })
}

function _markString(str, find){
    const re = new RegExp(find, 'ig');
    return str.replace(re, (match) => '<mark>' + match + '</mark>');
}

function _removeAllPosts() {
    const allPosts = getElement('#all_posts');
    while (allPosts.firstChild) {
        allPosts.removeChild(allPosts.firstChild);
    }
}
