{
  'targets':[
    {
      'target_name':'<(module_name)',
      'include_dirs':[
        "<!(node -e \"require('nan')\")"
      ],
      'sources':[
        'node-SUSI.cpp',
        'node-SUSI-function-define.cpp'
      ],
      'conditions':[
        [
          'OS=="linux"',
          {
            'libraries':[
              '-lSUSI-4.00'
            ]
          }
        ],
        [
          'OS=="win"',
          {
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
    },

    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
  ]
}