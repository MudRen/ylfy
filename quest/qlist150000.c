mapping *quest = ({
     ([      "quest":                "��Ҷ��",
        "diff":                 2,
        ]),
     ([      "quest":                "���۷�",
        "diff":                 2,
        ]),
     ([      "quest":                "��ѩ����",
        "diff":                 2,
        ]),
     ([      "quest":                "��÷��",
        "diff":                 2,
        ]),
     ([      "quest":                BLK "��ĵ��" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "ˮ��",
        "diff":                 2,
        ]),
     ([      "quest":                "���¾����Ͼ�",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
