mapping *quest = ({
     ([      "quest":                "������",
        "diff":                 5,
        ]),
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "������",
        "diff":                 2,
        ]),
     ([      "quest":                WHT "�ײ軨" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                HIC "����" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "��ɽ����",
        "diff":                 2,
        ]),
     ([      "quest":                "ˮ��",
        "diff":                 2,
        ]),
     ([      "quest":                "���¾�����ʮ���¡�",
        "diff":                 3,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
