mapping *quest = ({
     ([      "quest":                "��",
        "diff":                 2,
        ]),
     ([      "quest":                "�����Ҷ��",
        "diff":                 2,
        ]),
     ([      "quest":                "���",
        "diff":                 2,
        ]),
     ([      "quest":                "��˹����",
        "diff":                 2,
        ]),
     ([      "quest":                "�������䵶",
        "diff":                 2,
        ]),
     ([      "quest":                "���¾����ڰ��¡�",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
