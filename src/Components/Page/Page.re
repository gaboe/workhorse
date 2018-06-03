module GetPage = [%graphql
  {|
  query getPage($name: String!){
    page(name:$name){
      name,
      content
    }  }
|}
];

module GetPageQuery = ReasonApollo.CreateQuery(GetPage);

let q = GetPage.make(~name="Test", ());

let component = ReasonReact.statelessComponent("Page");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <GetPageQuery variables=q##variables>
        ...(
             ({result}) =>
               switch result {
               | Loading => <div> (ReasonReact.string("Loading")) </div>
               | Error(error) =>
                 <div> (ReasonReact.string(error##message)) </div>
               | Data(response) =>
                 switch response##page {
                 | None => <div> (ReasonReact.string("Nothing found")) </div>
                 | Some(page) =>
                   <div> (ReasonReact.string(page##content)) </div>
                 }
               }
           )
      </GetPageQuery>
    </div>
};