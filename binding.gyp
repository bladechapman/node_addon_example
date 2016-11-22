{
    "targets": [
        {
            "target_name": "nan_addon",
            "sources": [ "nan_hello.cc" ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        },
        {
            "target_name": "node_addon",
            "sources": [ "v8_hello.cc" ]
        }
    ]
}
