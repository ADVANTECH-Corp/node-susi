{
  'targets': [
    {
      'target_name': 'node-SUSI',
      'include_dirs' : [
  	"<!(node -e \"require('nan')\")"
			],
      'conditions': [ 
        ['OS=="linux"', {
              'sources': [ 'node-SUSI.cpp',  'node-SUSI-function-define.cpp'],
              'libraries': [ '-lSUSI-4.00' ],
        }],
        ['OS=="win"', {
              'sources': [ 'node-SUSI.cpp',  'node-SUSI-function-define.cpp'],
              'libraries': [ 'Susi4.lib' ],
        }]
      ]
    }
  ]
}
