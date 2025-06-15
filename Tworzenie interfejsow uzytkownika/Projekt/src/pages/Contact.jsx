import { useState } from 'react';
import { motion } from 'framer-motion';
import { useForm } from 'react-hook-form';
import { yupResolver } from '@hookform/resolvers/yup';
import * as yup from 'yup';

// Schemat walidacji
const schema = yup.object().shape({
    name: yup.string().required('Imię i nazwisko jest wymagane').min(3, 'Minimum 3 znaki'),
    email: yup.string().required('Adres e-mail jest wymagany').email('Nieprawidłowy adres e-mail'),
    message: yup.string().required('Wiadomość jest wymagana').min(10, 'Minimum 10 znaków'),
});

export default function Contact() {
    const [submitted, setSubmitted] = useState(false);

    const {
        register,
        handleSubmit,
        reset,
        formState: { errors }
    } = useForm({
        resolver: yupResolver(schema)
    });

    const onSubmit = (data) => {
        console.log('Dane wysłane:', data);
        setSubmitted(true);
        reset();
    };

    return (
        <div className="max-w-3xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100">
            <motion.h1
                initial={{ opacity: 0, y: -20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ duration: 0.5 }}
                className="text-4xl font-bold mb-8 text-center"
            >
                Kontakt
            </motion.h1>

            <motion.p
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ duration: 0.5, delay: 0.2 }}
                className="text-lg mb-10 text-center text-gray-700 dark:text-gray-300"
            >
                Masz pytania? Skontaktuj się z nami, a odpowiemy najszybciej jak to możliwe.
            </motion.p>

            <motion.div
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ duration: 0.5, delay: 0.4 }}
                className="bg-white dark:bg-gray-800 shadow-md rounded-lg p-6 space-y-6"
            >
                <div className="space-y-2">
                    <h2 className="text-xl font-semibold text-blue-600">Dane kontaktowe</h2>
                    <p className="text-gray-700 dark:text-gray-300">
                        📧 Email:{' '}
                        <a href="mailto:kontakt@mcs-system.pl" className="text-blue-600 hover:underline">
                            kontakt@mcs-system.pl
                        </a>
                    </p>
                    <p className="text-gray-700 dark:text-gray-300">
                        📞 Telefon:{' '}
                        <a href="tel:+48123456789" className="text-blue-600 hover:underline">
                            +48 123 456 789
                        </a>
                    </p>
                    <p className="text-gray-700 dark:text-gray-300">
                        🏢 Adres:{' '}
                        <a
                            href="https://maps.google.com?q=ul.+Częściowa+10,+Warszawa"
                            target="_blank"
                            rel="noopener noreferrer"
                            className="text-blue-600 hover:underline"
                        >
                            ul. Częściowa 10, 00-000 Warszawa
                        </a>
                    </p>
                </div>

                <form onSubmit={handleSubmit(onSubmit)} className="space-y-4">
                    <div>
                        <label className="block text-sm mb-1 text-gray-700 dark:text-gray-300">Imię i nazwisko *</label>
                        <input
                            {...register('name')}
                            className={`w-full border rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500 dark:bg-gray-700 dark:text-gray-100 ${
                                errors.name ? 'border-red-500 dark:border-red-500' : 'border-gray-300 dark:border-gray-600'
                            }`}
                            placeholder="Jan Kowalski"
                        />
                        {errors.name && <p className="text-red-500 text-sm mt-1">{errors.name.message}</p>}
                    </div>

                    <div>
                        <label className="block text-sm mb-1 text-gray-700 dark:text-gray-300">Adres e-mail *</label>
                        <input
                            {...register('email')}
                            className={`w-full border rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500 dark:bg-gray-700 dark:text-gray-100 ${
                                errors.email ? 'border-red-500 dark:border-red-500' : 'border-gray-300 dark:border-gray-600'
                            }`}
                            placeholder="jan@example.com"
                        />
                        {errors.email && <p className="text-red-500 text-sm mt-1">{errors.email.message}</p>}
                    </div>

                    <div>
                        <label className="block text-sm mb-1 text-gray-700 dark:text-gray-300">Wiadomość *</label>
                        <textarea
                            {...register('message')}
                            rows="4"
                            className={`w-full border rounded px-4 py-2 focus:outline-none focus:ring-2 focus:ring-blue-500 dark:bg-gray-700 dark:text-gray-100 ${
                                errors.message ? 'border-red-500 dark:border-red-500' : 'border-gray-300 dark:border-gray-600'
                            }`}
                            placeholder="Treść wiadomości..."
                        />
                        {errors.message && <p className="text-red-500 text-sm mt-1">{errors.message.message}</p>}
                    </div>

                    <button
                        type="submit"
                        className="bg-blue-600 hover:bg-blue-700 text-white px-6 py-2 rounded shadow w-full transition"
                    >
                        Wyślij wiadomość
                    </button>

                    {submitted && (
                        <motion.p
                            initial={{ opacity: 0 }}
                            animate={{ opacity: 1 }}
                            className="text-green-600 font-medium mt-2"
                        >
                            Dziękujemy! Wiadomość została wysłana.
                        </motion.p>
                    )}
                </form>

                <div className="pt-8">
                    <iframe
                        width="100%"
                        height="300"
                        title="Mapa z lokalizacją"
                        frameBorder="0"
                        scrolling="no"
                        marginHeight="0"
                        marginWidth="0"
                        src="https://www.openstreetmap.org/export/embed.html?bbox=21.0078%2C52.2285%2C21.0158%2C52.2311&layer=mapnik&marker=52.2298%2C21.0118"
                        className="rounded shadow"
                    ></iframe>
                </div>
            </motion.div>
        </div>
    );
}
