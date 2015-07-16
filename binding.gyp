{
  'targets':[
    {
      'target_name':'node-SUSI',
      'include_dirs':[
        "<!(node -e \"require('nan')\")"
      ],
      'conditions':[
        [
          'OS=="linux"',
          {
            'sources':[
              'node-SUSI.cpp',
              'node-SUSI-function-define.cpp'
            ],
            'libraries':[
              '-lSUSI-4.00'
            ],

          },

        ],
        [
          'OS=="win"',
          {
            'sources':[
              'node-SUSI.cpp',
              'node-SUSI-function-define.cpp'
            ],
            'libraries':[
              'Susi4.lib'
            ],
            'conditions':[
              [
                'target_arch=="ia32"',
                {
                  'library_dirs':[
                    'C:\\Program Files\\Advantech\\SUSI\\SDK\\SUSI4\\lib\\x86'
                  ]
                }
              ],
              [
                'target_arch=="x64"',
                {
                  'library_dirs':[
                    'C:\\Program Files\\Advantech\\SUSI\\SDK\\SUSI4\\lib\\x64'
                  ]
                }
              ]
            ]
          }
        ]
      ]
    }
  ]
}