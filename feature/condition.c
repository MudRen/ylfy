
#include <condition.h>

mapping conditions;

mapping query_conditions()
{
	return conditions;
}

//������������ж�״̬��
nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;
	
	if( !mapp(conditions) || !(i=sizeof(conditions)) )
		return 0;
	
	cnd = keys(conditions);
	update_flag = 0;
	cnd -= ({ "0" }); //���� cnd = 0 ��bug.
	while(i--)
	{
		//����һ���ֹcondition = 0 ��bug. 
        if( !cnd[i] ) continue;
		cnd_d = find_object(CONDITION_D(cnd[i]));
		
		if( !cnd_d )
		{
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));
			
			if( err || !cnd_d )
			{
				log_file("condition.err",sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",CONDITION_D(cnd[i]), this_object(), err));
				map_delete(conditions, cnd[i]);
				continue;
			}
		}
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		
		if( conditions[cnd[i]] < 1 )
			map_delete(conditions, cnd[i]);
		
		update_flag |= flag;
	}
	
	if( !sizeof(conditions) )
		conditions = 0;
	
	return update_flag;
}

//�γ��ж�״̬
nomask void apply_condition(string cnd, mixed info)
{
	object env;
	string env_name;

	if ( file_size(CONDITION_D(cnd)+".c")<1 
		&& file_size("/binaries"+CONDITION_D(cnd)+".b")<1 )
	{
		if ( objectp(env=environment()) ) env_name=base_name(env);
		else env_name="�޻���";
		log_file("condition.err", "����: "+this_object()->query("id")+" �� "+env_name+" �ж� "+cnd+"\n");
		return;
	}

	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}

//�ж�״��
nomask mixed query_condition(string cnd)
{
	if( !mapp(conditions) || undefinedp(conditions[cnd]) )
		return 0;
	
	return conditions[cnd];
}
 
//����������ж�״̬
nomask void clear_condition(int flag)
{
	int i, over;
	string *cnd;
	
	if ( !mapp(conditions) || !(i=sizeof(conditions)) )
		return;
	
	cnd = keys(conditions);
	while (i--)
	{
		//ͶƱ���Ʋ������
		if ( cnd[i]=="vote_clear" || cnd[i]=="vote_suspension" )
			continue;
		//��������������Ĳ����ж�������ʱ��flag = 1��
		if ( !flag )
		{
			if (cnd[i]=="killer" 
				|| cnd[i]=="bonze_drug" 
				|| cnd[i]=="bonze_jail")
				continue;
		}
		// ÿ����һ��ֻ��ȥɱ��һ�εļ�¼
		if ( cnd[i] == "killer" )
		{
			over = conditions["killer"]-500;
			if ( over > 0 ) conditions["killer"] = over;
			else map_delete(conditions, cnd[i]);
			continue;
		}
		
		map_delete(conditions, cnd[i]);
	}
}

