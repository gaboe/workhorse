let component = ReasonReact.statelessComponent("SaveButton");

let make = (~onBtnClick, _children) => {
  ...component,
  render: _self =>
    <div>
      <button
        onClick=(_ => onBtnClick()) 
        style=(
          ReactDOMRe.Style.make(
            ~backgroundColor="#db4d3f",
            ~border="white",
            ~borderRadius="5px",
            ~fontSize="35px",
            ~margin="10px",
            ()
          )
        )>
        (ReasonReact.string("Save"))
      </button>
    </div>
};