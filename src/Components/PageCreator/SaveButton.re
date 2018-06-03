let component = ReasonReact.statelessComponent("SaveButton");

let make = (~isDisabled: bool, ~onBtnClick, _children) => {
  ...component,
  render: _self =>
    <div>
      <button
        disabled=(isDisabled)
        onClick=(_ => onBtnClick()) 
        >
        (ReasonReact.string("Save"))
      </button>
    </div>
};