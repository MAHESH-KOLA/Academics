import React, { useCallback, useEffect, useState } from "react";
import ReactQuill from "react-quill";
import EditorToolbar, { modules, formats } from "./EditorToolbar";
import "react-quill/dist/quill.snow.css";
import "./TextEditor.css";
//import { useHistory } from "react-router-dom";
import axios from 'axios';

function Add() {
 // let history = useHistory();
  const [userInfo, setuserInfo] = useState({
    title: '',
    description: '',
    information: '',
    tags: '',
    demoLink: '',
    sourceCode: ''
  });
  const handleChange = (e) => {
    const { name, value } = e.target;
    setuserInfo({
      ...userInfo,
      [name]: value
    });
  };

  const onChangeValue = (e) => {
    setuserInfo({
      ...userInfo,
      [e.target.name]:e.target.value
    });
  } 
  const ondescription = (value) => {
    setuserInfo({ ...userInfo,
      description:value
    });
  } 
  const oninformation = (value) => {
    setuserInfo({ ...userInfo,
      information:value
    });
  } 
  const [isError, setError] = useState(null);
  const addDetails = async (event) => {
    try {
      event.preventDefault();
      event.persist();
      if(userInfo.description.length < 50){
        setError('Required, Add description minimum length 50 characters');
        return;
      }
      axios.post(`http://localhost:8080/addArticle`, {
        title: userInfo.title,
        description: userInfo.description,
        information: userInfo.information,
      })
      .then(res => {
        if(res.data.success === true){
         // history.push('/');
        }
      })
    } catch (error) { throw error;}    
  } 

return ( 
<>

  <div className="App">
    <div className="container">
      <div className="row"> 
        <form onSubmit={addDetails} className="update__forms">
          <h3 className="myaccount-content"> Add  </h3>

          <div className="form-row">
            <div className="form-group col-md-12">
              <label className="font-weight-bold"> Title <span className="required"> * </span> </label>
              <input type="text" name="title" value={userInfo.title} onChange={onChangeValue}  className="form-control" placeholder="Title" required />
            </div>

             <label>Tags:</label>
        <select name="tags" value={userInfo.tags} onChange={handleChange} required>
          <option value="">Select a tag</option>
          <option value="tag1"> Software Engineer</option>
          <option value="tag2"> Software Developer </option>
          <option value="tag3"> Full Stack Developer</option>
        </select>


            <div className="clearfix"></div>
            <div className="form-group col-md-12 editor">
              <label className="font-weight-bold"> Description <span className="required"> * </span> </label>
            <EditorToolbar toolbarId={'t1'}/>
            <ReactQuill
              theme="snow"
              value={userInfo.description}
              onChange={ondescription}
              placeholder={"Write something awesome..."}
              modules={modules('t1')}
              formats={formats}
            />
            </div>
            <br />
            <div className="form-group col-md-12 editor">
              <label className="font-weight-bold"> Additional Information  </label>
            <EditorToolbar toolbarId={'t2'}/>
            <ReactQuill
              theme="snow"
              value={userInfo.information}
              onChange={oninformation}
              placeholder={"Write something awesome..."}
              modules={modules('t2')}
              formats={formats}
            />
            </div>
            <br />
            <label>View Demo (YouTube Link):</label>
        <input type="url" name="demoLink" value={userInfo.demoLink} onChange={handleChange}  />

        <label>Source Code (Upload/Download):</label>
        <input type="file" name="sourceCode" onChange={handleChange}  />
            <br />
            <br />
            {isError !== null && <div className="errors"> {isError} </div>}
            <div className="form-group col-sm-12 text-right">
              <button type="submit" className="btn btn__theme"> Upload  </button>
            </div> 
          </div> 
        </form>
      </div>
    </div>
  </div>
</>
)
}
export default Add