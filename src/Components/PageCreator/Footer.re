let component = ReasonReact.statelessComponent("Footer");

let make = _children => {
  ...component,
  render: _self =>
    <div className="footer">
      <div>
        (ReasonReact.string("Created with " ++ {js|♥|js} ++ " by Gabo"))
      </div>
      <div> (ReasonReact.string("Written in Reason+React")) </div>
    </div>
};