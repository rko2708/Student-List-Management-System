struct Trie 
{
    string key ;
    unordered_map < char , Trie* > map ;
} ;

Trie * getNewTrieNode() 
{
    Trie * node = new Trie ;
    return node ;
}


void insert ( Trie*& root , string & str )
{
    Trie * temp = root ;
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        char x = str[i] ;
        if ( temp -> map.find(x) == temp -> map.end() )
        {
            temp -> map[x] = getNewTrieNode() ;
            
        }
        temp = temp -> map[x] ;
    }
    temp ->  key = str ;
}


int search ( Trie *& root , string str )
{
    Trie * temp = root ;
    if ( temp == NULL )
    return 0 ;
    for ( int i = 0 ; i < str.length() ; i++ )
    {
      char x = str[i] ;
      if ( temp -> map.find(x) != temp -> map.end() )
      {
          temp = temp -> map[x] ;
      }
      else
      return 0 ;
    }
    if ( temp -> key == str )
    return 1 ;
    else
    return 0 ;
}



signed main()
 {
	int t ;
	cin >> t ;
	while ( t-- )
	{
	    int n ;
	    Trie * root = getNewTrieNode() ;
	    cin >> n ;
	    string arr[n] ;
	    for ( int i = 0 ; i < n ; i++ )
	    {
	        cin >> arr[i] ;
	        insert ( root , arr[i] ) ;
	        
	    }
	    
	    string searchstr ;
	    cin >> searchstr ;
	    cout << search ( root , searchstr ) << endl ;
	}
	
}
