// made by lks

inherit ROOM;

void create()
{
        set("short", "·��");
        set("long", @LONG
������ǻ���С��Ķ�·�ڣ���������ģ�û��ʲ�����ڸ����߶���
������һ�����ѵ�С·��������һ��С�����ϵ��˼Ҳ����࣬���Ƕ���
���ճ������������Ϣ���������
LONG );
        set("valid_startroom",1);
        set("exits", ([
                "west" : "/d/changan/lmroad1",
				"east" : __DIR__"sroad1",
        ]));
        set("class","Ѫ����");
        set("outdoors", "����" );
        setup();
        replace_program(ROOM);
}
