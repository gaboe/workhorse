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

let component = ReasonReact.statelessComponent("Page");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <div>
      <GetPageQuery variables=GetPage.make(~name, ())##variables>
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