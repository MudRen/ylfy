//daguandao.c  ��ٵ�
inherit  ROOM;

void  create  ()
{
        set("short",  "��ٵ�");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ�򺯹ȹأ�
��������ֱ�ﳤ���ǣ���������ȥ����ɽ�ıؾ�֮·�书��
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"      :  __DIR__"daguandao2",
                "west"      :  "/d/wugongzhen/guandao1",
        ]));
        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

