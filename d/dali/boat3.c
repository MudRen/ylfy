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
  "north" : __DIR__"boat2",
  "west" : __DIR__"tading",
]));
        set("outdoors","dali");

        setup();
}
