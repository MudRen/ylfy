//bye enter

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long",@LONG
������һ����ʯ���ϣ�����С�ﾲ���ĵģ�������·��
�����龰��ȫ��һ�������ܾ��������е㲻�Ծ���
LONG
        );

        set("exits", ([
                "west" : __DIR__"qingshixiang1",
                "east" : __DIR__"qingshixiang3",
            ]));
        setup();
        replace_program(ROOM);       
}


