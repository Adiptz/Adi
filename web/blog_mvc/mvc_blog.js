import View from "./view.js"
import Model from "./model.js";

class Controller {
    constructor() {
        this.model = new Model();
        this.view = new View();

        this.view.bindAddPost(this.handleAddPost);
        this.view.bindGetPosts(this.handleGetPost);
        this.view.bindSearch(this.handleSearch);

        this.model.bindAddPost(this.view.addPost);

        //TODO - CALL ONLOAD EVENT ?
    }

    handleAddPost = newPost => {
        this.model.addPost(newPost)
    };

    handleGetPost = () => {
        return this.model.getPosts();
    };

    handleSearch = input => {
      return this.model.searchPosts(input);
    };
}

export default Controller;



