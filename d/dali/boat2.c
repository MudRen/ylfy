inherit ROOM;
void create()
{
        set("short", "�����ۼװ�");
        set("long", @LONG
��ɫ���̣���ɫ������΢���������羰���ˡ�һ������ȭ�о��������Ů�˵�
��Ц����ʱ�ĴӴ����д���������ϸ�����������ƺ��������ŵ͵͵ı���֮�����봬
�ϵĻ���Ц�Ｋ����Ǣ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"boat1",
  "south" : __DIR__"boat3",
]));

        set("objects", ([
        __DIR__"npc/shuishou" : 2,
        __DIR__"npc/mother": 2,
                        ]) );

        set("outdoors","dali");

        setup();
}
