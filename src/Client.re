open ApolloInMemoryCache;

[@bs.val] external url : string = "process.env.REACT_APP_SERVER_URL";

type dataObject = {
  .
  "__typename": string,
  "id": string
};

let inMemoryCache =
  createInMemoryCache(~dataIdFromObject=(obj: dataObject) => obj##id, ());

let httpLink = ApolloLinks.createHttpLink(~uri=url, ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());