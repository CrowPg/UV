insert into CLIENT(num, nom, prenom, adresse, date_nais, tel, sexe) values (
	client_seq.NEXTVAL,
	'coulomb',
	'francois',
	'4, rue liberte',
	to_date('02121980','DDMMYYYY'),
	'06456780',
	'm'
);

insert into CLIENT(num, nom, prenom, adresse, date_nais, tel, sexe) values (
	client_seq.NEXTVAL,
	'bernard',
	'dupont',
	'120, square zola',
	to_date('19081972','DDMMYYYY'),
	'01345678',
	'm'
);

insert into CLIENT(num, nom, prenom, adresse, date_nais, tel, sexe) values (
	client_seq.NEXTVAL,
	'corda',
	'nathalie',
	'66, bv napoleon III',
	to_date('02101977','DDMMYYYY'),
	'06455790',
	'f'
);

insert into CLIENT(num, nom, prenom, adresse, date_nais, tel, sexe) values (
	client_seq.NEXTVAL,
	'pierre',
	'alexandre',
	'1, place des martyres',
	to_date('19081972','DDMMYYYY'),
	'01645870',
	'f'
);

commit;
