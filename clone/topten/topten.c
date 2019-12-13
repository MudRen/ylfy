// topten.c
// 1998/12/17 Modified by Winder

#include <ansi.h>

inherit ITEM;

mapping *exp_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *richman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *oldman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *force_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
/*
mapping *pks_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
*/
mapping *literate_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *unarmed_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *dodge_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *thief_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *axe_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *blade_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *throwing_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *fork_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *hammer_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),
});
mapping *staff_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *sword_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *whip_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
/*
mapping *club_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
*/
string *whichpart =
({
        HIY"��һ��    ʮ��������а�  --------------------  B1"NOR,
        HIY"�ڶ���    ʮ��������а�  --------------------  B2"NOR,
        HIY"������    ʮ���������а�  --------------------  B3"NOR,
        HIY"���İ�    ����ڹ�����  ----------------------  B4"NOR,
        HIY"�����    ���ѧ����  ----------------------  B5"NOR,
        HIY"������    �������ɱ��  ----------------------  B6"NOR,
        HIY"���߰�    ����������͵  ----------------------  B7"NOR,
        HIY"�ڰ˰�    ����������  ------------------------  B8"NOR,
        HIY"�ھŰ�    ����������  ------------------------  B9"NOR,
        HIY"��ʮ��    ��ȭ�޵�������  --------------------  B10"NOR,
        HIY"��ʮһ��  ̤ѩ�޺ۿ����  --------------------  B11"NOR,
        HIY"��ʮ����  ����������--------------------------  B14"NOR,
        HIY"��ʮ����  �˷������  ------------------------  B15"NOR,
        HIY"��ʮ�İ�  ��ԭ�˴�  ------------------------  B16"NOR,
        HIY"��ʮ���  ���������ȿ�  ----------------------  B12"NOR,
//        HIY"��ʮ����  �����������  ----------------------  B13"NOR,
});
string printdate = NATURE_D->game_time();

void create()
{
       
        set_name(HIY"������Ӣ�۰�"NOR, ({ "hero board", "board" }));
        set_weight(800);
        set("unit", "��");
        set("long","���Ǽ���������һ��Ӣ��������������Ľ���������(READ)�����ġ�\n");
        set("value", 1600);
        set("no_get", 1);
        set("no_steal", 1);
        set("no_put", 1);
        set("no_beg", 1);
        set("material", "paper");
}

void init()
{
        object ob;

        seteuid(getuid());
        if( ob = new("/clone/topten/magic-rice") )
                if( (exp_topten=ob->query( "exp_topten" ))
                        &&(richman_topten=ob->query("richman_topten"))
                        &&(oldman_topten=ob->query("oldman_topten"))
                        &&(force_topten=ob->query("force_topten"))
//                        &&(pks_topten=ob->query("pks_topten"))
                        &&(unarmed_topten=ob->query("unarmed_topten"))
                        &&(dodge_topten=ob->query("dodge_topten"))
                        &&(literate_topten=ob->query("literate_topten"))
                        &&(thief_topten=ob->query("thief_topten"))
                        &&(axe_topten=ob->query("axe_topten"))
                        &&(blade_topten=ob->query("blade_topten"))
                        &&(throwing_topten=ob->query("throwing_topten"))
                        &&(fork_topten=ob->query("fork_topten"))
                        &&(hammer_topten=ob->query("hammer_topten"))
                        &&(staff_topten=ob->query("staff_topten"))
                        &&(sword_topten=ob->query("sword_topten"))
//                        &&(club_topten=ob->query("club_topten"))
                        &&(whip_topten=ob->query("whip_topten")) )
                        destruct( ob );
                else
                        write(CYN"\n�������а�������⣡��֪ͨ����ִ����\n\n"NOR);
        else
                write(CYN"\n�������а�������⣡��֪ͨ����ִ����\n\n"NOR);

        add_action("do_read", "read");
}

int do_read( string arg )
{
        int i;
        string si;
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});

        switch( arg )
        {
                case "hero board":
                case "board":
                case "b":
                case "������Ӣ�۰�":
                        write( "���Ķ���������Ӣ�۰񡷣�ֻ������д�ţ�\n" );
                        write( "--------------------------------------------------------\n" );
                        for( i = 0; i < sizeof(whichpart); i++ )
                                write( "    "+whichpart[i]+"\n" );
                        write( "--------------------------------------------------------\n" );

                        write( "                          ----"+printdate+"����\n" );
                        write( "��Ҫ�Ķ��ڼ���\n" );
                        break;
                case "B1":
                case "b1":
                case "��һ��":
                case "ʮ��������а�":
                        write( "                    ��"+HIC"ʮ��������а�"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( exp_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B2":
                case "b2":
                case "�ڶ���":
                case "ʮ��������а�":
                        write( "                    ��"+HIC"ʮ��������а�"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( richman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B3":
                case "b3":
                case "������":
                case "ʮ���������а�":
                        write( "                    ��"+HIC"ʮ���������а�"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( oldman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B4":
                case "b4":
                case "���İ�":
                case "����ڹ�����":
                        write( "                    ��"+HIC"����ڹ�����"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( force_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B5":
                case "b5":
                case "�����":
                case "���ѧ����":
                        write( "                    ��"+HIC"���ѧ����"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( literate_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B6":
                case "b6":
                case "������":
                case "�������ɱ��":
                        write( "                    ��"+HIC"�������ɱ��"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
/*
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( pks_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
*/
                        write( "    ��ʱ����  \n" );
                        write( "========================================================\n" );
                        break;
                case "B7":
                case "b7":
                case "���߰�":
                case "����������͵":
                        write( "                    ��"+HIC"����������͵"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( thief_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );

                        }
                        write( "========================================================\n" );
                        break;
                case "B8":
                case "b8":
                case "�ڰ˰�":
                case "����������":
                        write( "                    ��"+HIC"����������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( sword_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B9":
                case "b9":
                case "�ھŰ�":
                case "����������":
                        write( "                    ��"+HIC"����������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( blade_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B10":
                case "b10":
                case "��ʮ��":
                case "��ȭ�޵�������":
                        write( "                    ��"+HIC"��ȭ�޵�������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( unarmed_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B11":
                case "b11":
                case "��ʮһ��":
                case "̤ѩ�޺ۿ����":
                        write( "                    ��"+HIC"̤ѩ�޺ۿ����"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( dodge_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B12":
                case "b12":
                case "��ʮ����":
                case "�ļ�������":
                        write( "                    ��"+HIC"�ļ�������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( throwing_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B13":
                case "b13":
                case "��ʮ����":
                case "�˷������":
                        write( "                    ��"+HIC"�˷������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( whip_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B14":
                case "b14":
                case "��ʮ�İ�":
                case "��ԭ�˴�":
                        write( "                    ��"+HIC"��ԭ�˴�"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 8; i++ )

                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( hammer_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B15":
                case "b15":
                case "��ʮ���":
                case "���������ȿ�":
                        write( "                    ��"+HIC"���������ȿ�"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( staff_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
/*
                case "B16":
                case "b16":
                case "��ʮ����":
                case "�����������":
                        write( "                    ��"+HIC"�����������"NOR+"��\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( club_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
*/
                   default:
                        return 0;
        }
        return 1;
}