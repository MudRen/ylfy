mapping *quest = ({
     ([      "quest":                "�廨Ь",
        "diff":                 2,
        ]),
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "ͭ��",
                "diff":                 2,
        ]),
     ([      "quest":                "���",
        "diff":                 2,
        ]),
     ([      "quest":                "�廨��",
        "diff":                 2,
        ]),
     ([      "quest":                YEL "��õ��" NOR,
        "diff":                 3,
        ]),
     ([      "quest":                "���¾�",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
